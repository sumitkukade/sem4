README

1. Assignment Validation 2
	1. validated some data
2. Pre-requisite
	1. Python 2.7.9
        2. "python-dateutils" package (sudo easy_install python-dateutil)
	3. virtualenv (sudo pip install virtualenv)
3. Validations handled
	1. works if the order of the fields is not fixed
	2. there could be no field title for some fields
	3. it handles leap_year/invalid_date like "30-feb-2016"
	4. prints invalid if name/lastname,date,mobile_number,email_id is not given
