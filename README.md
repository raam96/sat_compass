# sat_compass: Calculate Bearing Using 3 GPS

## Introduction
The "sat_compass" project is designed to calculate the true heading of a vessel using data from three GPS modules. The true heading is determined based on the Haversine formula and bearing formula, representing the geographical north direction, also known as true north.

True north points towards the Earth's geographic North Pole, which is the fixed point where the Earth's axis of rotation intersects the surface. It is distinct from magnetic north, which is the direction towards the Earth's magnetic North Pole. Magnetic north can vary over time and across different locations due to the Earth's magnetic field not aligning with its rotational axis.

Please note that this project calculates true north. If you require the heading relative to magnetic north, you would need a magnetometer or compass sensor to account for the Earth's magnetic field.

## How It Works
The "sat_compass" project calculates the distance and bearing between three GPS modules: module 1, module 2, and module 3. Here's how it works:

- Calculate the distance and bearing between GPS module 1 and GPS module 2:

    - `d12 = distance(lat1, lon1, lat2, lon2)`
    - `b12 = bearing(lat1, lon1, lat2, lon2)`

- Calculate the distance and bearing between GPS module 2 and GPS module 3:

    - `d23 = distance(lat2, lon2, lat3, lon3)`
    - `b23 = bearing(lat2, lon2, lat3, lon3)`

- Calculate the distance and bearing between GPS module 3 and GPS module 1:

    - `d31 = distance(lat3, lon3, lat1, lon1)`
    - `b31 = bearing(lat3, lon3, lat1, lon1)`

- Calculate the average distance and bearing between the three GPS modules:

    - `d_avg = (d12 + d23 + d31) / 3`
    - `b_avg = (b12 + b23 + b31) / 3`

- Calculate the true heading of the vessel:

    - `true_heading = (b_avg + d_avg) % 360`

This formula calculates the true heading by adding the average distance and bearing between the three GPS modules and ensuring the result falls within the range of 0 to 359 degrees.

## Usage
To use the "sat_compass" project:

1. Connect the GPS modules to your microcontroller or computer.

2. Initialize and configure the GPS modules to provide necessary data, including latitude and longitude.

3. Read the latitude and longitude data from each GPS module and use it to calculate distance and bearing between the modules using the provided formulas.

4. Calculate the average distance and bearing between the GPS modules.

5. Determine the true heading of the vessel using the true heading formula.

This project is ideal for applications where accurate location and heading information are crucial, such as satellite tracking or navigation.

## Author
This project, "sat_compass," is authored by raam@96. For inquiries, contributions, or additional information, please contact the author.

## Disclaimer
This code is intended for educational and research purposes. It provides a foundation for calculating true north-based headings. Users should exercise responsibility and ethical consideration when using this code. Ensure that you have the necessary permissions and legal authorization for your specific application.

**USE AT YOUR OWN RISK**.
