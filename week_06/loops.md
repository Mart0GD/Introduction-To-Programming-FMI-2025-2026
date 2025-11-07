# Конструкции за итерация в С. Цикли.
***Итерация*** - повторението на даден процес.

## В С има две категории цикли:
* **Entry controlled** - тези, за които първо трябва да бъде удоволетворено някакво условие, за да може тялото им да се изпълни. При тях първо правим проверка, после изпълняваме логиката в цикъла.
  - **for-loop**
  - **while-loop**
* **Exit controlled** - тези, за които първо бива изпълнено тялото им, а после се извършва някаква проверка. При тях имаме гаранция, че ще се изпълнят поне 1 път.
  - **do-while**

## Конструкции за итерация. Синтаксис. Семантика и област на действие.
**a) Синтаксис**

 <img width="806" height="166" alt="image" src="https://github.com/user-attachments/assets/f8fc3c27-4e32-4f91-9b62-cb734493ca6f" />    

 

 

**б) Семантика и област на действие(scope)**
* **iteration-statement**  на семантично ниво е блок от код, който служи за осигуряването на многократното изпълнение на друг блок от код, който ще наричаме тяло на цикъл(**loop body**)

* **iteration-statement** като област на действие е строго подмножество на областта на действие, в която пишем даден цикъл (напр. ф-ята int main() {-//-})
* **loop body** като област на действие е строго подмножество на областта на действие на *iteration-statement*

## for-loop (entry-controlled)
**a) Синтаксис**
~~~
  for (initialization_expression(opt); control_expression(opt); update_expression(opt))
  {loop_body}
  
      OR

   for (declaration_expression(opt); control_expression(opt); update_expression(opt))
  {loop_body}
~~~
* **initialization_expression** - израз, в който инициализираме променливата, служеща за контрол на изпълнението на тялото на цикъла
* **control_expression** - израз, задаващ условието за изпълняване на тялото на цикъла. Трябва да е от числов тип
* **update_expression** - в израз, в който задаваме стъпка/ изменение в стойността на променливата от *initialization_expression*

**б) Особености**
Може би сте забелязали, че в шаблона на синтаксиса на *for-loop* след всеки expression седи таг **opt**. Това е стандартно означение за думата optional, т.е. всеки един от показаните изрази може да бъде пропуснат. Условието е просто да поставяме **;**, за да остане валиден синтаксисът.

#### Пример1: Пропускаме всички изрази.
Такъв тип iteration_statement води до безкраен цикъл.

<p>
  
```c
for (; ;)
{
  // body_loop
}
```
</p>

#### Пример2: Пропускаме израз за инициализация/ декларация на "ръководна" променлива
Използваме променлива от областта на действие на int main(). Както вече казахме, *iteration_statement* като област на действие е строго подмножество на областта на действие на променливите в *int main()*

<p>
  
```c
#include <stdio.h>
int main()
{
    int iter = 0; // iterational variable
    for (; iter < 5; ++iter)
    {
        printf("Iteration number = %d\n", iter);
    }
}
```
</p>

#### Пример3: Пропускаме израз актуализация на ръководната променлива
Можем да пропуснем този израз в *iteration_statement* и да имплементираме такава актуализация в тялото на цикъла. Също така, можем да зададем такава логика и в *control_statement*

<p>
  
```c
#include <stdio.h>

int main()
{
    int iter = -1; // iterational variable
    // First method
    for (iter = 0; iter < 5;)
    {
        printf("Iteration number = %d\n", iter++);
    }
    // Second method
    for (iter = 0; iter++ < 5;)
    {
        printf("Iteration number = %d\n", iter);
    }
    
    return 0;
}
```
</p>

**в) Ход на изпълнението на кода на for-loop** 
<img width="800" height="400" alt="image" src="https://github.com/user-attachments/assets/b9decc48-80a0-4168-bf23-f3419199a472" />

## while-loop (entry-controlled)
**a) Синтаксис**
~~~
  while(control_expression)
                  statement   
~~~

* тялото на цикъла се изпълнява, докато условието *control_expression* е удоволетворено. За разлика от ***for-loop***, тук инициализацията, както и актуализацията на ръководната променлива(loop variable) се случва ръчно. Пишем инициализацията извън iteration_statement-a на нашия ***while-loop***, а логиката за актуализиране на ***loop_variable*** се случва в тялото на цикъла

**б) Ход на изпълнението на кода на while-loop** 
<img width="800" height="400" alt="image" src="https://github.com/user-attachments/assets/c853d9d0-c3d3-4c92-936d-e5d4caae1491" />


## do_while-loop (exit-controlled)
***do_while-loop*** е *exit-controlled*, което значи, че първо се изпълнява тялото на цикъла, после се извършва проверка за пре-изпълняване на цикъла. Този flow-control ни осигурява поне едно изпълнение на тялото на цикъла.

**a) Синтаксис**
~~~
  do 
      statement
  while(control_expression);   
~~~

* аналогично на **while-loop***, инициализацията и актуализацията на ***loop_variable*** се извършва ръчно.
  
**б) Ход на изпълнението на кода на do_while-loop** 
  <img width="800" height="400" alt="image" src="https://github.com/user-attachments/assets/9188bf5f-d9a8-47b8-a6f6-e77ced184a86" />

  ## Вълшебните думи **break** и **continue**
* **break** - Тази думи би трябвало да ни бъде позната в контекстта на **switch** конструкциите. Е, за наше облекчение при циклите те имат същото поведение. При достигане на ред съдържащ ключовата дума **break** в тялото на **switch** или някоя от показаните в този урок конструкции за цикъл, то изпълнението им прекъсва.
* **continue** - Тази ключова дума се използва **само** в контекстта на циклите. При достигане на **continue** в тялото на даден цикъл, то пропускаме текущата итерация и в случай, че ***control_statement-a*** ни е удоволетворен, то започваме изпълнението на следващата итерация.

#### Пример:
 <p>
  
```c
#include <stdio.h>

int main()
{
    int iter = 0;
    while(iter < 5){
      if (iter == 3)
      continue;
      printf("Iteration number %d\n", iter++);
    }
    return 0;
}
```
</p>

#### Изход:
Iteration number 0

Iteration number 1

Iteration number 2

Iteration number 4
