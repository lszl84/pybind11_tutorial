import build.advanced_module as m

department = m.Department.HR

print(f"We are in the {department} department")

employee = m.Person("John", "Manager", m.Department.HR)

print(f"{employee.name} is a {employee.position} in the {employee.department} department")
print("Reassigning employee to the Engineering department")
employee.ReassignDepartment(m.Department.Engineering)

print(f"{employee.name} is a {employee.position} in the {employee.department} department")
