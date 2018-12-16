# Data Visualization Final Report

## DataVisualization, Group D 

###### Jia Deng(jia_deng@brown.edu), Jiayi Wang(jiayi_wang3@brown.edu)

###### Mingyu Wang(mingyu_wang@brown.edu), Xiaohui Mo(xiaohui_mo@brown.edu)

###### ENGN2912B Fall18 S01 Scientific Programming in C++, Date Submitted: Dec, 2018

  

## Project Overview

In this project, our final goal is to visualize a map showing businesses like shops and businesses near a location, based on academic data from yelp website.

The project could be briefly divided into 3 parts, setting up the database, building the interface of C++ with database and data visualization using C++ and Qt.

 
## Goals and Objectives

For this project, our goal is to develop a new approach for users to look up information about businesses in the certain area, Providence, in this case. To further explain, this application will be able to achieve the following goals.

  

First, the user can look up business data by name or type. Second, the user is able to sort the local businesses by their opening status to see if they are open or not under a certain time period. Third, the user can simply type in their location data and range they want to search and then all businesses within this area will show up. The result number is also decided by the user.

* **Objective 1: Data query and parsing.**

* **Objective 2: Setting up background.**

* **Objective 3: Getting input data.**

* **Objective 4: Displaying data.**

  

## Software Architectural Design

  

* **Required External Libraries**

		QCustom Plot
		SQLite3
		json
		QApplication
		QtSql
		QSqlDatabase
		QSqlQuery
		QtDebug
		QDir
		QString

* **Functional Block Diagrams**

![](https://lh3.googleusercontent.com/Sug0rLlzBOpCUhsbf2qkaGQa2kKrKmzc7SVLxO4FAxwtLWu3oP0n_-Evwq18CSt7gFZrKddRAvzZvWjBpvehm8qiRDPyiH9Hq3DRKZs_4QYcoqVE22X5WgFiGqa5AG5WyiUHdiJi)

  

* **Data Flow Diagrams**


![](https://lh3.googleusercontent.com/ocnjBdgJ-Q7sd9mxcPdhYMk1Tle-Rvprs1qVqBx6F5en2CaYKXLjyblUBpeTNhGJwxgGri-rqbWSpkmpsEmi8afXZu6mRjAUXkcEMMlXhBfuiKj86wO_2RYldFdPNPERSeobp3iU)

* **UML Diagrams showing Object Definition/Inheritance**

![](https://lh4.googleusercontent.com/rxPKMeqwdxl8xL2A0RwfsM5U3hqObI1tNsGRJ_8pRpUAB0o4hBBGarWyN_h6Ex9tMiv1X3yKqtkHu66xZntKitOyLV5A6fBQfBFoMuD2GgFfeKuYPGH7rQA3sWg2z7HXHeo26wvw)

  

## Interface Descriptions

* **Graphical Interface**

![](https://lh5.googleusercontent.com/hJa-1-RvFnOzz0_meFvLx26sgxxGhIfdV5arTnKioD6I0XD4KAk53oVLgsi8C0VchgKacQsD1M18Gkz3i51SD6jsfKC1kSNlEL1E4e_GxvpZKcCKrTMkIVXuQWViRPCxX-IvHbcQ)

* **Data Visualization**

![](https://lh6.googleusercontent.com/7p0DchbVy_0yJFLCX9SsA-f8MCsROvLSDHxZsEP0rvI0iNPyhLekJq6GslX2oK1ZBcZpcQdPsh5PjPiCh1k-JeoDFPwag2OOJbU_8IYCbKaJtWHJH4d3wwOzCBpuRU7t87hjBcHB)


* **Exception Handling**

	-- Out of boundary

	If there are some restaurant that are out of boundary and cannot be displayed on the 	map, the team will use a pop-up window to display "out of range" error message.

	--No result

	If there is no result in given search criteria, the team will use a pop-up window to display "0 result found" error message.

  
  

## Testing and Evaluation

  

* **Operating system(s) and software compiler/library version(s) tested**

The team have tested the program under several operating environment, here are the lists:

	Microsoft Windows 10, i7-8550U, Qt Creator 4.8.0 based on Qt 5.12.0 (MSVC 2015, 32 bit).

	Apple mac OS X, i5-7267U, Qt Creator 4.8.0 based on Qt 5.12.0 (Clang 10.0 (Apple), 64 bit).

	Apple mac OS X, i5-7360U, Qt Creator 4.8.0 based on Qt 5.12.0 (Clang 10.0 (Apple), 64 bit).

	Apple mac OS X, i5-5257U, Qt Creator 4.8.0 based on Qt 5.12.0 (Clang 10.0 (Apple), 64 bit).

  

* **Description of functional testing to date**

	**Convert:** (all with DB Browser for SQLite)

	checking total number of records and types of records attributes

	checking types of records attributes

	randomly choosing 5 records and compare its values

	**Filter:**

	checking with not empty string name and open

	checking with not empty string name

	checking with empty string name and open

	checking with empty string name


	**Mainwindow:**

	take integer input and display it

	**Linking qcustomplot and Mainwindow:**

	take integer input and plot a curve

	**Linking Mainwindow and filter and qcustomplot:**

	no business through output

	current location outside of map

	zero result count input

	business outside of map

	**Built a test.db to test filter cpp file**

	**Implemented filter_test.cpp working on test.db**

  

* **Instructions for compiling and running the software**

	Compiling: Download project file from github -> open Qt Creator -> open project file "team_final.pro" -> configure project based on your computer specifications -> run the program

	Running encapsulated file: Download project file from github -> locate ‘release’ subfolder -> run the team_final.app file

## Conclusions

During the past month, the team built a functional data visualization project based on Yelp database. According to user input including business name/type, user location and range, the system displays the business names and locations on the map. Our initial goal was to search specific business name or tag in Providence, to search all businesses around a location and to search open businesses, sorted by hard coded rank, then display business information. During implementation, the team changed our goal to search a specific business name/tag or all businesses around a location whether open or doesn’t matter, sorted by customized rank. which makes more sense to customer needs. The team also noticed if all information is displayed, the GUI layout would be in a mess. Therefore, the team decided to only display locations and names. The team have achieved all of our initial goals and objectives and did better.

#### Future Work

--Get user’s location through GPS  
--Promote the application to the range of US  
--Change the plot point to button that can show the whole information of the business  

#### Author Contributions

* **Jia deng and Mingyu Wang** - Construct database and build interface between data and C++

* **Xiaohui Mo and Jiayi Wang** - Design UI and implement functions to achieve data visualization
