const confSomething = () => {
	return new Promise((res, rej) => {
		let status = Math.random() < 0.5;
		if(status) res(`Success!`)	
		else rej()
	})
}

const promiseSomething = () => {
	return new Promise((res, rej) => {
		confSomething()
			.catch(() => { return rej(`Error!`) })
			.then((data) => { return res(data) })
	})
}

promiseSomething()
	.then(res => console.log(res))
	.catch(err => console.log(err))
