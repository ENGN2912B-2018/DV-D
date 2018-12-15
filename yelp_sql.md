----------------------------
Look up distance to a business by name/tag(manhattan distance) 
SELECT name, latitude, longitude, location FROM (
  SELECT business.name, business.open, business.latitude, business.longitude, abs(business.latitude-41.82) + abs(business.longitude-(-71.4)) AS location
  FROM business
) AS x
WHERE location < 2 and open = '1'
order by location asc
limit 10

input: latitude, longitude, distance
Studio 539 Flowers
Fellini Pizzeria

----------------------------
Look up distance to a business by name/tag(manhattan distance) 
SELECT name, latitude, longitude, location FROM (
  SELECT business.name, business.open, business.latitude, business.longitude, abs(business.latitude-41.82) + abs(business.longitude-(-71.4)) AS location
  FROM business
) AS x
WHERE location < 2
order by location asc
limit 10

input: latitude, longitude, distance
Studio 539 Flowers
Fellini Pizzeria

g++ main.cpp -l sqlite3
./a.out
