const doSomething = () => {
	return Math.random() < 0.5
}

const confSomething = () => {
	return new Promise((res, rej) => {
		let status = doSomething();
		if(status) res(`Success!`)	
		else rej()
	})
}

const promiseSomething = () => {
	return new Promise((res, rej) => {
		confSomething()
			.catch(() => { return rej(`Error confSomething`) })
			.then((data) => { return res(data) })
	})
}

promiseSomething()
	.then(res => console.log(res))
	.catch(err => console.log(err))
