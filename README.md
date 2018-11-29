# DV-D
###### Jia Deng, Jiayi Wang, Mingyu Wang, Xiaohui Mo

## Design Philosophy

For this project, our final goal is to visualize a map to show some useful information based on the original data downloaded from the yelp website. Our job will be briefly divided into 3 parts, setting up the database, build the interface of C++ with database and data visualization using C++.

## Build Instruction
The raw data set we downloaded is in JSON format. Utilizing the programming language of Python, the data is stored in SQLite for the convenience of subsequent operations. According to the filtering requirements, we store the filtered data into C++ Classes. After a series of numerical calculation, the data are visualized into user-friendly pictures.

## Usage Documentation
Consider the functionality of this project, since we are now at the beginning of developing this program, we did not have a fully designed usage documentation yet, but for the purpose of future planning, it should have the following features:

* **Look up business data by reviews, ratings and city** - users will be able to sort the local restaurants by the ratings received from customers

* **Confirm the opening status of a business** - users will be able to sort the local restaurants by their opening status, to see if they are open or not under a certain time period

* **Look up businesses by names** - users can check the distance to a certain restaurant by entering the restaurant name

* **Look up businesses by tags** - users can check the distance to a certain group of restaurants by entering restaurant types

* **Distance to businesses** - users can simply type in their location data and range they want to search and then all restaurants within this area will show up

## Source dataset
https://www.yelp.com/dataset/download
