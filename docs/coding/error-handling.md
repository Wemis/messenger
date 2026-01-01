# Error Handling
- No errno
- No global error state
- `result_t` returned explicitly
## Examples
```C
result_t sum(int a, int b, int *result) {      // result_t returned explicitly
	if (math_sum(a, b, result) == MATH_ERR) {  // Handling errors
		return SUM_ERR;
	}
	
	return OK;    // Success
}
```

`result_t` enum is available here <a href="https://github.com/Wemis/messenger/blob/master/shared/include/shared/result.h">result.h</a>