ALIAS LOCALES CREADOS:
    checkout -> co
    commit -> cm
    status -> st
    config -> cf
    stash -> st
    pop -> p


ALIAS GLOBALES CREADOS:
    branch -> br
    add -> a
    clone -> cl
    merge -> mg
    log -> lg
    tag -> tg

BISECT
    En la rama mejora3 he creado varios commits marcados con mensajes como 
    "Commit con error", "commit sin error". Cuando he tenido una alternancia
    de commits, empecé con git bisect start, luego he ido marcando cada commit con: 

        git bisect good
        git bisect bad
    
    Segun tenia errores o no, y finalmente he utilizado git bisect reset para volver
    al commit original del que empecé.

HOOKS:
    - Se ha creado el hook post-commit, que después de hacer git commit -m "", se realiza
    un push de manera automática

    - Se ha añadido un hook que comprueba que no hayan commits sin mensajes, mostrando
    un mensaje de error si lo intentamos.
