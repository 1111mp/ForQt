function request(verb, endpoint, obj) {
    return new Promise((resolve, reject) =>
                       {
                           print('request: ' + verb + ' ' + BASE + (endpoint ? '/' + endpoint : ''))
                           var xhr = new XMLHttpRequest()
                           xhr.onreadystatechange = function() {
                               print('xhr: on ready state change: ' + xhr.readyState)
                               if(xhr.readyState === XMLHttpRequest.DONE) {
                                   var res = JSON.parse(xhr.responseText.toString())
                                   if(xhr.status === 200) {
                                       resolve(res)
                                   } else {
                                       reject(res)
                                   }
                               }
                           }
                           xhr.open(verb, BASE + (endpoint ? '/' + endpoint : ''))
                           xhr.setRequestHeader('Content-Type', 'application/json')
                           xhr.setRequestHeader('Accept', 'application/json')
                           var data = obj ? JSON.stringify(obj) : ''
                           xhr.send(data)
                       })
}
