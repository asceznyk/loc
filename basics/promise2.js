let p1 = Promise.resolve(200)
let p2 = 'Dog'
let p3 = Promise.resolve(400)

Promise.all([p1,p2,p3])
	.then(res => console.log(res))
	.cath(err => console.log(err))


