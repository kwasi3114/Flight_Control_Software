// PID gains
float k_p = 1.0, k_i = 0.0, k_d = 0.0;

// Time delta
float dt = 0.01; // 10 ms loop

// Integral and previous error terms (persist across calls)
float alt_error_integral = 0.0;
float alt_error_prev = 0.0;

float x_error_integral = 0.0, x_error_prev = 0.0;
float y_error_integral = 0.0, y_error_prev = 0.0;
float z_error_integral = 0.0, z_error_prev = 0.0;

void attitude_control(float desired_altitude, float current_altitude,
                      float p_d, float q_d, float r_d,
                      float x_ang_vel, float y_ang_vel, float z_ang_vel,
                      float roll, float pitch, float mass)
{
    // Altitude control
    float alt_error = desired_altitude - current_altitude;
    alt_error_integral += alt_error * dt;
    float alt_error_deriv = (alt_error - alt_error_prev) / dt;

    float u1 = (1 / (cos(roll) * cos(pitch))) * (
        k_p * alt_error +
        k_i * alt_error_integral +
        k_d * alt_error_deriv +
        mass * fabs(grav)
    );
    alt_error_prev = alt_error;

    // Attitude (angular velocity) control
    float ex = p_d - x_ang_vel;
    x_error_integral += ex * dt;
    float ex_deriv = (ex - x_error_prev) / dt;
    float pd = k_p * ex + k_i * x_error_integral + k_d * ex_deriv;
    x_error_prev = ex;

    float ey = q_d - y_ang_vel;
    y_error_integral += ey * dt;
    float ey_deriv = (ey - y_error_prev) / dt;
    float qd = k_p * ey + k_i * y_error_integral + k_d * ey_deriv;
    y_error_prev = ey;

    float ez = r_d - z_ang_vel;
    z_error_integral += ez * dt;
    float ez_deriv = (ez - z_error_prev) / dt;
    float rd = k_p * ez + k_i * z_error_integral + k_d * ez_deriv;
    z_error_prev = ez;

    // Output control signals
    std::cout << "Thrust u1: " << u1 << std::endl;
    std::cout << "pd: " << pd << ", qd: " << qd << ", rd: " << rd << std::endl;
}
