from typing import List


def maxArea(height:List[int]) -> int:  
    lp = 0
    rp = len(height)-1
    mwater = 0

    while(lp < rp):
        lh, rh = height[lp], height[rp]
        area = abs(rp-lp) * min(lh, rh)
        if height[lp] <= height[rp]: lp += 1
        elif height[rp] <= height[lp]: rp -= 1
        if area >= mwater: mwater = area

    return mwater

