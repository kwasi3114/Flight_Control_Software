float p = 0.5;
float i = 0.3;
float d = 0.1;

float desired_x;
float desired_y;

float current_x;
float current_y;

float desired_roll;
float desired_pitch;

float x_error;
float x_error_integral = 0;
float x_error_diff;
float x_prev_error = 0;

float y_error;
float y_error_integral = 0;
float y_error_diff;
float y_prev_error = 0;


void position_controller(){
    x_error = desired_x - current_x;
    x_error_integral += x_error;
    x_error_diff = x_error - x_prev_error;
    x_prev_error = x_error;
    desired_roll = p*x_error + i*x_error_integral + d*x_error_diff; 
    
    y_error = desired_y - current_y;
    y_error_integral += y_error;
    y_error_diff = y_error - y_prev_error;
    y_prev_error = y_error;
    desired_pitch = p*y_error + i*y_error_integral + d*y_error_diff;
}