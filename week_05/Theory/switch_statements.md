# switch клаузи
Клаузите **switch** и **case** служат за управлението на хода на изпълнение на вашата програма.

## Синтаксис на switch клаузите
**switch** ( expression )

  **case** constant-expression_1 : statement_1
  
  **case** constant-expression_2 : statement_2
  
  .
  
  .
  
  .
  
  **case** constant-expression_n : statement_n
  
  **default** : statement

## *expression*, *constant-expression_x*, *statement_x*, *brake*, *default*
* **expression** - интегрална(целочислена) променлива/ израз.
* **constant-expression_x** - константна целочислена променлива/ литерал. Една **switch** конструкция може да има много constant-expression-и, но всеки два трябва да имат различна стойност.
* **statement_x** - блокът код, който ще се изпълни, ако *expression* е равно *constant-expression_x*.
* **break** - изпълнението на програмата започва от първия *case*, за който *constant-expression* е равен на  *expression* и приключва или с излизането от *switch* конструкцията, като по пътя си изпълнява кода под всеки следващ *case* (така нареченият **fall-through**) или до достигане на **brake**. Можете да използвате **brake** за прекратяването на изпълнението на кода в *switch* конструкцията.
* **default** - *statement* или тялото на *default* се изпълнява, ако *expression* не съвпада с никой един от *constant-expression-ите* описани в тялото един *switch*.

### Важно:
В началото на тялото на един *switch* можем да правим декларации, но не и инициализации и дефиниции. *switch* клаузата пренасочва изпълнението на програма директно в към някой от изброените *case-ове* в него
