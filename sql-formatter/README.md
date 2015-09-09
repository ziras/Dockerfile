sql-formatter
=============

Format SQL using the sql-formatter used by phpMyAdmin.

Usage
-----

```bash
docker run --rm foliolin/sql-formatter show tables from information_schema
```

or

```bash
docker run --rm foliolin/sql-formatter 'select * from information_schema.TABLES;'
```
