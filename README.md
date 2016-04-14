# genphpclass
c++ qt command line tool for making php classes

Use
====

	./genphpclass yourClassName [key1] [key2] 

Keys
====

 Use v:v1,v2 to declare variables $v1, $v2

 Use m:f1,f2 to declare methods $v1, $v2

 Use e:parentClass1,parentClass2 to inherit behaviour from parent classes

 Use i:interface1,interface2 to declare implementation of interfaces

 Use c:childClass1,childClass2 to make code of child classes

 Use -p to declare settings and getters

 Use -w to write file named yourClassName.php

 Use prefix # to generate protected functions or variables, for example: v:#protectedVariable

 Use prefix . to generate private functions or variable, for example: m:.privateFunc

  
	
Example
====
	
	./genphpclass Dragon v:score,health,items m:fly,eat i:Flying e:FairyAnimal -w -p

will save in tool directory file named Dragon.php

	<?php
	class Dragon implements Flying extends FairyAnimal{
	var $score;
	var $health;
	var $items;
	function setScore( $p ) {$this->score = $p;return $this;}
	function getScore( ) {return $this->score;}
	function setHealth( $p ) {$this->health = $p;return $this;}
	function getHealth( ) {return $this->health;}
	function setItems( $p ) {$this->items = $p;return $this;}
	function getItems( ) {return $this->items;}
        function fly( ){ };
        function eat( ){ };
	}
	?>


Using modifiers for scopes
===============

    ./genphpclass mySuperClass m:#protectedMethod,.privateMethod v:.hiddenVar,#protectedVar -p

will generate

    <?php
    class mySuperClass{
    private $hiddenVar;
    protected $protectedVar;
    private function setHiddenVar( $p ) {$this->hiddenVar = $p;return $this;}
    private function getHiddenVar( ) {return $this->hiddenVar;}
    protected function setProtectedVar( $p ) {$this->protectedVar = $p;return $this;}
    protected function getProtectedVar( ) {return $this->protectedVar;}
         protected function protectedMethod( ){ };
         private function privateMethod( ){ };
    }
    ?>

Making child classes
=============

For example, command

    ./genphpclass Animal c:Cat,Dog

will output

    // CLASSNAME:Animal
    // CHILDS:2

    <?php
    class Animal{
    }
    ?>

    // CLASSNAME:Cat
    // CHILDS:0

    <?php
    require_once "Animal.php";
    class Cat extends Animal{
    }
    ?>

    // CLASSNAME:Dog
    // CHILDS:0

    <?php
    require_once "Animal.php";
    class Dog extends Animal{
    }
    ?>

Key -r
=========

Command

	./genphpclass Dog e:Animal i:woof -r

will output

	// CLASSNAME:Dog
	// CHILDS:0
	
	<?php
	require_once "woof.php";
	require_once "Animal.php";
	class Dog implements woof extends Animal{
	}
	?>

Batch processing
================

Use bash script genproject.sh

	./genproject.sh /path/to/specifications

Required file must contain parameters of genphpclass tool at each line.
Look for the example at the file named project.
