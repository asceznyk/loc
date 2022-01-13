Number.prototype.clamp = function (min, max) {
	return Math.min(Math.max(this, min), max)
}

function rgb(r, g, b) {
	r = r.clamp(0, 255);
	g = g.clamp(0, 255);
	b = b.clamp(0, 255);

	let base16 = [0,1,2,3,4,5,6,7,8,9,'A','B','C','D','E','F'];
	let hex = '';
	
	for(let c of [r, g, b]) {
		let [v, i] = [0, 0];
		while(true) {
			i++;
			v = 16*i;
			if(v > c) {
				i -= 1;
				v -= 16;
				break;
			} 
		}
		hex += base16[i]+''+base16[c-v];
	}

	return hex;
}

console.log(rgb(126,173,181))




