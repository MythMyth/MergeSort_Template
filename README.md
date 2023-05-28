## Merge sort using template C++<br/>
An container can store element and execute merge sort for element it stored<br/>
typename T must support the operator corresponding to the comparison function:<br/>
- **operator <** if using std::less compare
- **operator >** if using std::greater compare
- **operator <=** if using std::less_equal compare
- **opreator >=** if using std::greater_equal compare
- ...<br/><br/>

Merge sort often using for its sorting operation, not for its result. So callback function should be set.<br/>
Explaination for callback function comming soon.
