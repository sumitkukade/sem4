function isValidName(id, name){
	var re = /^[A-Za-z]+$/;
	var isValid = re.test(name)
	if(isValid)

		return present(isValid, "", id);
	else
		return present(isValid, "Error: Invalid "+id, id);
}

function isValidPhone(id, phone){
	var re = /^\d{10}$/;
	isValid = re.test(phone)
	if(isValid)
		return present(isValid, "", id)
	else
		return present(isValid, "Error: Invalid phone", id)
}

function isValidEmail(id, email){
	var re = /^[a-z\.\_\-0-9]+@[a-z]+\.[a-z]+$/;
	isValid = re.test(email)	
	if(isValid)
		return present(isValid, "", id)
	else
		return present(isValid, "Error: Invalid Email", id)
}

function present(isValid, errMsg, id){
	
	if(isValid)
		var text = document.createTextNode('');
	else
		var text = document.createTextNode(errMsg);

	var child = document.getElementById(id);
	child.parentNode.appendChild(text, child);
	
}

function validate()
{
	
    var fname = document.getElementById("first_name").value;
    var mname = document.getElementById("middle_name").value;
    var lname = document.getElementById("last_name").value;
    var phone = document.getElementById("phone").value;
    var email = document.getElementById("email").value;
    isValidName("first_name", fname);
    isValidName("middle_name", mname);
    isValidName("last_name", lname);
    isValidPhone("phone", phone);
    isValidEmail("email", email);
}