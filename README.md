# sat_compass
Calculate Bearing using 3 GPS

The true heading calculated using the Haversine formula and bearing formula is based on the geographical north direction, also known as true north. True north is the direction towards the Earth's geographic North Pole, which is the fixed point on the Earth's surface where the Earth's axis of rotation meets the surface.
True north is different from magnetic north, which is the direction towards the Earth's magnetic North Pole. The Earth's magnetic field is not aligned with the Earth's rotational axis, and the magnetic North Pole is not fixed in place. As a result, the direction of magnetic north changes over time and is different in different locations on the Earth's surface.
To calculate the heading relative to magnetic north, you will need to use a magnetometer or compass sensor in addition to the GPS modules. The magnetometer or compass sensor can be used to measure the Earth's magnetic field and calculate the heading relative to magnetic north.

// Calculate distance and bearing between GPS module 1 and GPS module 2
d12 = distance(lat1, lon1, lat2, lon2)
b12 = bearing(lat1, lon1, lat2, lon2)

// Calculate distance and bearing between GPS module 2 and GPS module 3
d23 = distance(lat2, lon2, lat3, lon3)
b23 = bearing(lat2, lon2, lat3, lon3)

// Calculate distance and bearing between GPS module 3 and GPS module 1
d31 = distance(lat3, lon3, lat1, lon1)
b31 = bearing(lat3, lon3, lat1, lon1)

Then, you can calculate the average distance and bearing between the three GPS modules using the following formulas:

d_avg = (d12 + d23 + d31) / 3
b_avg = (b12 + b23 + b31) / 3

Finally, you can use the average distance and bearing to calculate the true heading of the vessel using the following formula:

true_heading = (b_avg + d_avg) % 360

where b_avg is the average bearing between the three GPS modules, d_avg is the average distance between the three GPS modules, and true_heading is the true heading of the vessel.

This formula calculates the true heading of the vessel by adding the average distance and bearing between the three GPS modules, and then taking the modulus of the result with 360 to ensure that the heading is within the range of 0 to 359 degrees.


calculate the true heading of a vessel using three GPS modules, you will need to do the following:

    1.  Connect the GPS modules to your microcontroller or computer.

    2.  Initialize the GPS modules and configure them to output the necessary data, such as latitude, longitude, and altitude.

    3.  Read the latitude and longitude data from each GPS module and use it to calculate the distance and bearing between the three GPS modules. This can be done using the         Haversine formula and bearing formula, respectively.

    4.  Calculate the average distance and bearing between the three GPS modules.

    5.  Use the average distance and bearing to calculate the true heading of the vessel.
