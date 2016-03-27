/* Enumerated type creates set of constants numbered 0 and upward*/
typedef enum {MODE_A, MODE_B, MODE_C, MODE_D, MODE_E} mode_t;

int switch3(int *p1, int *p2, mode_t action)
{
	int result = 0;
	switch(action){
	case MODE_A:
	case MODE_B:
	case MODE_C:
	case MODE_D:
	case MODE_E:
	default:
	}
	return result;
}