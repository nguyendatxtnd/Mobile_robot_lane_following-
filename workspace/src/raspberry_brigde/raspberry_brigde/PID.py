import time
import numpy as np

class PID:
    def __init__(self, Kp=0.0, Ki=0.0, Kd=0.0, integrator_min=-1.0, integrator_max=1.0):
        self.Kp = Kp
        self.Ki = Ki
        self.Kd = Kd
        
        self.integral = 0.0
        self.prev_error = None
        self.prev_time = None
        self.integrator_min = integrator_min
        self.integrator_max = integrator_max

    def reset(self):
        self.integral = 0.0
        self.prev_error = None
        self.prev_time = None

    def update(self, error, current_time=None):
        if current_time is None:
            current_time = time.time()

        if self.prev_time is None:
            dt = 1e-3 
        else:
            dt = current_time - self.prev_time
            if dt <= 0.0:
                dt = 1e-3 
        
        # --- P (Proportional) ---
        P = self.Kp * error

        # --- I (Integral) ---
        self.integral += error * dt
        self.integral = np.clip(self.integral, self.integrator_min, self.integrator_max)
        I = self.Ki * self.integral

        # --- D (Derivative) ---
        if self.prev_error is None:
            D = 0.0
        else:
            derivative = (error - self.prev_error) / dt
            D = self.Kd * derivative

        self.prev_error = error
        self.prev_time = current_time

        return P + I + D

