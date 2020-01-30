#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<math.h>


int main() {

	//game variables
	float alpha = 0;
	float x1 = 0;
	float y1 = 0;
	float x2 = 0;
	float y2 = 0;

	//controls render section
	bool redraw = true;

	al_init();
	al_init_primitives_addon();

	//allegro variables
	ALLEGRO_DISPLAY* display = al_create_display(500, 500);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60); //60 FPS

	//set up event queue, start timer
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//TIMER SECTION (handles physics)
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			alpha += 3.14;

			//math is frickin beautiful, yo.
			x1 = 200*sin(20 * alpha)*cos(alpha)+250;
			y1 = 200*sin(20 * alpha)*sin(alpha)+250;

			x2 = 100 * sin(20 * alpha)*cos(alpha) + 250;
			y2 = 100 * sin(20 * alpha)*sin(alpha) + 250;

			redraw = true;
		}

		//lets you close game window with the x button
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		//RENDER SECTION
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			//al_clear_to_color(al_map_rgb(0, 0, 0)); //clears the screen

			al_draw_filled_circle(x1, y1, 2, al_map_rgb(alpha*100, 50, alpha*100));
			al_draw_filled_circle(x2, y2, 2, al_map_rgb(alpha * 100, 50*alpha, alpha * 100));
			al_flip_display();
		}
	}

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
