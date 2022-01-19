function bouncingBall(h, bounce, window) {
	if(h > 0 && (bounce > 0 && bounce < 1) && window < h) {
		let b = -1;
		while(h > window) {
			b += 2;
			h *= bounce;
		}
		return b;
	} 
	return -1;
}

let r = bouncingBall(30.0, 0.66, 1.5);
console.log(r)
