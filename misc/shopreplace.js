const fetchActions = () => {
	const actions = [
		{
			'id':1,
			'name':'Action 1',
			'type':'WATCH_VIDEO'
		},
		{
			'id':2,
			'name':'Action 2',
			'type':'SHARE'
		},
		{
			'id':3,
			'name':'Action 3',
			'type':'TEXT'
		},
		{
			'id':4,
			'name':'Action 4',
			'type':'EMAIL'
		},
		{
			'id':5,
			'name':'Action 5',
			'type':'PLAY'
		}
	]

	return new Promise((res, rej)=> {
		setTimeout(() => res(actions), 1000)
	})
} 

const fetchTagsByAction = (action) => {
	const textTags = [
		{
			'id':1,
			'name':'DROP_MENU',
			'value':''
		}
	]

	const emailTags = [
		{	
			'id':1,
			'name':'DROP_MENU',
			'value':''
		},
		{
			'id':2,
			'name':'OrderID',
			'value':'12345'
		}
	]

	return new Promise((res, rej) => {
		setTimeout(() => {
			if(action.type == 'TEXT') {
				res(textTags)
			} else if(action.type == 'EMAIL') {
				res(emailTags)
			}
		}, 1000)
	})
}


const fetchOrderById = (orderid) => {
	const order = {
		'some':'text',
		'key':'12345',
		'more': 'items'
	}

	return new Promise((res, rej) => {
		setTimeout(() => res(order), 1000)
	})
}

async function getTargetActions () {
	let targets = []
	const actions = await fetchActions()
	await Promise.all(actions.map(async (action) => {
		if(action.type == 'TEXT' || action.type == 'EMAIL') {
			let tags = await fetchTagsByAction(action); 
			for (let tag of tags) {
				if(tag.name == 'OrderID') {	
					action.type = 'SHOP'
					targets.push(action)
					break;
				}
			}
		}
	}))
	return targets
}

getTargetActions().then((res)=>console.log(res))


