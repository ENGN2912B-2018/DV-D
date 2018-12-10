Get the businesses in Providence, RI. Results should be sorted by stars in descending order. Return top 10 businesses. 
select name, latitude, longitude
from business
where city = 'Providence' and state = 'RI'
order by stars desc
LIMIT 10

input: None

Look up business by name/tag
select name, latitude, longitude
from business
where business.name = ?
order by stars desc
LIMIT 10

input: name/tag

Look up distance to a business by name/tag(manhattan distance) 
SELECT name, latitude, longitude, location FROM (
  SELECT business.name, business.latitude, business.longitude, abs(business.latitude-41) + abs(business.longitude-(-71)) AS location
  FROM business
) AS x
WHERE location < 2
order by location asc
limit 20

input: latitude, longitude, distance

g++ main.cpp -l sqlite3
./a.out