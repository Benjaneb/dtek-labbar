## Which registers are saved and restored by your subroutine? Why?
$ra, $s0 and $s1 because they were used for further subroutine calling and saving values and the caller needs the potential already stored values to be saved.

## Which registers are used but not saved? Why are these not saved?
$a0, $a1, $v0 and $t0 because these registers are not meant for preserving values across calls.

## Assume the time is 16:53. Which lines of your code handle the '5'?
Lines 109-111 (before delay subroutine was written).