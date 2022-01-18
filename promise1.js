const doSomething = () => {
	return Math.random() < 0.5
}

const confSomething = () => {
	return new Promise((res, rej) => {
		let status = doSomething();
		if(status) res({"success":true})
		else rej({"success":false})
	})
}

let p = confSomething()

p
	.then(data => console.log(data))
	.catch(error => console.log(error))

