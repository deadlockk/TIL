# Control flow

* when 문

```
var x = 1
when(x){
  1 -> println("x=1")
  2 -> println("x=2")
  else -> {
    println("x는 1 또는 2가 아니다")
  }
}

```

* for 문

```
//Range for 문
for( x in 1..10 step 2 ){
  println(x)
}

//Collection for 문
var intArray = arrayOf(1, 10, 100)
for( item in intArray ){
  println(item)
}
```

* while 문
