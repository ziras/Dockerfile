clean:
	docker rmi foliolin/sql-formatter

demo:
	docker run --rm foliolin/sql-formatter 'select * from information_schema.TABLES;'

image:
	docker build -t foliolin/sql-formatter .
