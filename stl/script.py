import build.stl_module as m

n = 17
a = 10
b = 20

result = m.generate_random_integers(n, a, b)

print(f"Generated {n} random integers between {a} and {b}: {result}")
print(f"The type of the result is: {type(result)}")

print("Trying to call the function with invalid arguments...")

try:
    m.generate_random_integers(n, b, a)
except Exception as e:
    print(f"An exception occurred: {e}")
