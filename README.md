# TIL(Today I Learned)

Daily commit.

### Categories

* [Kotlin](#Kotlin)
* [Algorithm](#Algorithm)
* [DistributedSystem](#DistributedSystem)

---

### Kotlin

  ### NULL SAFETY - nullpointexception

  * 선언

  ```
  var name (변수이름) : String? = "상원"
  ```

  ---

  ### (컴파일러는 바로 null safety 변수에 접근할 수 없기 때문에 해제한 이후에 접근 해야 한다)

  * 강제 해제

    >>       

    >  ┍ㅡㅡㅡ┑

    > ㅣ name ㅣ  ------------------>  n a m e

    >  ┕ㅡㅡㅡ┙        !! 강제해제

    >>       

    ```
    var name : String? = "상원"

    println(name!!) //상원


    var name : String? = null

    println(name!!) //에러발생
    ```

  * 안전 해제 1

    ```
    println(name) // 상원    /* 자동적으로
                  // null       해제되어진다 */
    ```                

  * 안전 해제 2 (변수에 소속된 function 이나 하위 클래스에 접근하고자 할 때)

    >>       

    >  ┍ㅡㅡㅡ┑

    > ㅣ name ㅣ  ------------------>  n a m e

    >  ┕ㅡㅡㅡ┙          ? 해제

    >>       

    ```
    var name : String? = "상원"
    println(name?.length) // 2
  
    var name : String? = null
    println(name?.length) // 물음표는 null을 캐치하여 에러를 발생시키지 않고 null 값만 출력한다

    ```
  
  
 

---

### Algorithm

- 

---

### Distributed System

- 

---

## About

Based on the TIL idea from [jbranchaud/til](https://github.com/jbranchaud/til).
