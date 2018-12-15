import json
import sqlite3

# connect to db file
JSON_FILE = "yelp_academic_dataset_business.json"
DB_FILE = "yelp.db"
conn = sqlite3.connect(DB_FILE)
c = conn.cursor()
print('Opened Database Successfully')
create_s = "CREATE TABLE busess(id VARCHAR(255) NOT NULL, name VARCHAR(255) NOT NULL, full_adress VARCHAR(255) NOT NULL, city VARCHAR(255) NOT NULL, state VARCHAR(255) NOT NULL, latitude REAL, longitude REAL, stars REAL, review_count INT, open INT, PRIMARY KEY (id))"
conn.execute(create_s)in
print('Create Table Successfully')
conn.commit()

for line in open('/Users/julia/Desktop/db_convert/yelp_academic_dataset_business.json'):
    curr_b = json.loads(line)
    b_id, name, city, state, la, lo, stars, open = curr_b["business_id"], curr_b["name"], curr_b["city"], curr_b["state"], curr_b["latitude"], curr_b["longitude"], curr_b["stars"], curr_b["is_open"]
    data = [curr_b["business_id"], curr_b["name"], curr_b["address"], curr_b["city"], curr_b["state"], curr_b["latitude"], curr_b["longitude"], curr_b["stars"], curr_b["review_count"], curr_b["is_open"]]
    c.execute('insert into business values (?,?,?,?,?,?,?,?,?,?)', data)
    conn.commit()
    # print('insert into courses values ' + str(data) + " success")

c.close()
