# Problem
I am having difficults working with strings containing non-English characters.

# Set Up Notes
I use Visual Studio 2019 Community.  
The project is set to use a "Multi-Byte" character set. This may need tweaked later.

# Initial Generic Tests
## Test 1
### Explanation:
Shows how strings and wstrings differ when output to the console using the std::cout/std::wcout streams.  
### Results:
As expected, the standard string is shown completely with the Japanese characters replaced with question marks.  
The wide version fails to display at all, and even omits the "new line" at the end.

## Test 2
### Explanation:
A simple test that writes a string to an ofstream ofstream.  
### Results:
This displays the Japanese characters as question marks, while having the file encoded as UTF-8.  
All other characters display properly.

## Test 3
### Explanation:
Similar to test 2, but uses wstring and wofstream.  
### Results:
This does not seem to write to the file at all. I am unsure why.


# Targeted Tests
## Test 4
### Explanation:
After reading the 
	TBD