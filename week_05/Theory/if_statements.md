# Условният оператор *if*  
**if** е израз, контролиращ пътя на изпълнение на една програма. В С **if** позволява обработката на даден блок от код, когато е удоволетворено дадено условие.
Ако **test_statement** има стойност различна от нула, то условието ще е изпълнено.
<p>

```c
if (test_statement)
{
-//-
}
```
</p>

Ако искаме, но не задължително, можем след **if** да добавим и **else** клауза, която ще предизвика изпълнението на друг блок от код, когато условието ни не е изпълнено 
<p>

```c
if (test_statement)
{
-//-
}
else
{
-//-
}
```
</p>

<img width="423" height="74" alt="image" src="https://github.com/user-attachments/assets/bc6eb374-d6c1-49ac-b98b-403adb2f6056" />

### Особеност при работа с *if*
Ако под условен оператор **if** не са сложени фигурни скоби, то първият израз последващ if-клаузата ще бъде третиран като блок от код, който трябва да се изпълни, когато условието е удоволетворено

#### Пример: следните две if-клаузи са еквивалентни
<p>

```c
int myVar = 1;
if (myVar)
printf("Entered if-clause\n");
```
</p>

<p>

```c
int myVar = 1;
if (myVar)
{ printf("Entered if-clause\n"); }
```
</p>

### Вложени if-клаузи
#### Пример 1:

<p>

```c
if (horsePower > 200)
    if (isDiesel == 1)
        tax *= 1.5f;
    else
        tax *= 1.25f;
else
    tax *= 1.06f;
```
</p>

#### Пример 2:
В този пример вложеният if няма else-клауза. else винаги се асоциира с най-близкия if, така че би било подходящо да сложим скоби указващи началото и края на блока на външната if-клауза
<p>

```c
if (gradeEntry > 4) 
{
    if (gradeMidtrm >= 4)
        isTakingFinals = 1;
}
else
  isTakingFinals = 0;
```
</p>

#### Въпрос:
Какво ще се отпечата на конзолата при вход 14?
<p>

```c
int main()
{
    int num;
    printf("Enter a number\n");
    scanf("%d", &num);
    
    if (num > 10) // if_A
    if (num > 15) // if_B
    printf("Enter if_B\n");
    else
    printf("Else-clause belongs to if_?\n");
    
    return 0;
}
```
</p>

<details><summary><b>Отговор</b></summary> 
<p>
<img width="403" height="141" alt="image" src="https://github.com/user-attachments/assets/3bab790b-d53c-4de4-b049-9a9d2b59de51" />

</p>
</details>

## Вериги от if клаузи и else-if конструкции
Тъй като вече се запознахме с условния оператор **if**, то вече можем да осъществим по-сложни конструкции. Например можем да изградим поредица от проверки.
#### Пример:
Искаме потребител на нашата програма да въведе ден, месец и година. После искаме да проверим дали въведените от него числа са с валидни стойности. В случай, че не са, то задаваме стойности по подразбиране.
<p>

```c

int main()
{
    unsigned day, month, year;
    
    printf("Enter a day in the following order DD/MM/YY\n");
    scanf("%u %u %u", &day, &month, & year);
    
    if (day == 0 || day > 31)
    {
        printf("Invalid day!\n");
        day = 1; // default day
    }
    if (month == 0 || month > 12)
    {
        printf("Invalid month!\n");
        month = 1; // default month
    }
    if (year == 0 || year > 2025)
    {
        printf("Invalid year\n");
        year = 2025; // default year
    }
    
    return 0;

}
```
</p>

#### **Забележка**: Ако и трите условия са изпълнени, то ще влезем и в трите if блока. Но как моделираме ситуации, в които искаме да се изпълни тялото на точно един условен оператор?

## else-if клаузи
Започваме директно с пример и изпълнение. Искаме да напишем програма, която прочита от конзолата оценка от изпита по линейна алгебра на студент във ФМИ и да отпечата съответната реакцията на родителите му. 
<p>

```c
int main()
{
    unsigned grade;
    
    printf("Каква оценка изкара по линейна алгебра на изпита?\n");
    scanf("%u", &grade);
    
    if (grade == 2) 
    {
        printf("Догодина пак\n");
    }
    else if (grade == 3)
    {
        printf("Най-хубавата оценка!\n");
    }
    else if (grade == 4)
    {
        printf("Гордеем се с теб\n");
    }
    else if (grade == 5)
    {
        printf("Ще ти купим мечтания голф\n");
    }
    else if (grade == 6)
    {
        printf("Лъжеш :)\n");
    }
    else 
        printf("Ква е тая оценка??\n");
    
    return 0;

}
```
</p>

#### **Важно**:
В езика С *else-if* не отделна самостоятелна конструкция, а комбинация от конструкциите *else* и *if*. Както видяхме по- рано, ако условието на оператор *if* не е изпълнено и непосредствено след него има *else*, то ще се изпълни блокът на съответния *else*. Езици като C++, C#, Java, Go и Haskell също не правят изключение.


**Следните две програми са напълно еквивалентни.**

<p>

```c

if (conditional_statement_one)
{
    -//-
}
else if (conditional_statement_two)
{
    -//-
}

```
</p>

<p>

```c

if (conditional_statement_one)
{
    -//-
}
else
{
     if (conditional_statement_two)
     {
            -//-
     }
}

```
</p>
