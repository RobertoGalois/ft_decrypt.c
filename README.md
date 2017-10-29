# ft_decrypt.c
42 C exercice (http://www.42.fr/):

<b>UPDATE: before the struct s_perso had the "age" param as String, 
Here it is an Int.</b>

Write the function ft_decrypt. This function take a string in argument and split it in an array t_perso*[].
The array is delimited by a 0 value;

• The prototype is 
<code>t_perso **ft_decrypt(char *str);</code>

• The string passed as argument is formatted like this:
<code>Age|Name;Age2|Name2;Age3|Name3</code>

• unfilled fields are not initialized
(<code>Age|;Age2|Name2;|Name3</code>)

• Allowed function: malloc();

---

Ecrire une fonction ft_decrypt. Cette fonction prendra une chaine de caractères en paramètre et la découpera en un tableau de structure t_perso. Le tableau sera délimité par un 0.

• Cette fonction sera prototypée de la façon suivante :
<code>t_perso **ft_decrypt(char *str);</code>

• La chaine passée en paramètre sera formattée de la manière suivante :
<code>Age|Nom;Age2|Nom2;Age3|Nom3</code>

• Les champs non précisés ne seront pas initialisés

• Fonction autorisée: malloc();
