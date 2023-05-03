from typing import List


def maxArea(height:List[int]) -> int:  
    lp = 0
    rp = len(height)-1
    mwater = 0

    while(lp < rp):
        lh, rh = height[lp], height[rp]
        area = abs(rp-lp) * min(lh, rh)
        if area >= mwater: mwater = area
        if height[lp] <= height[rp]: lp += 1
        else: rp -= 1

    return mwater

