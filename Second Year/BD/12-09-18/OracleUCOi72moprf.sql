  CREATE TABLE prueba
  (edad number(2,0),
  nombre varchar2(40)
  );
  
  INSERT INTO prueba
  values(22,'Perez Perez, Jose');
  
  INSERT INTO prueba
  values(23,'Luque Leon, Alejandro');
  
  INSERT INTO prueba
  values(23,'Reyes Criado, Gonzalo');
  
  INSERT INTO prueba
  values(20,'Molina Prieto, Francis');
  
  SELECT *
    from prueba;
    
  SELECT *
    from prueba
    where edad=23;
    
      
  DELETE 
    FROM prueba;
    
  DELETE
    FROM prueba
    WHERE edad=22;
  
  UPDATE prueba
    SET edad=46
    WHERE edad=23;

  UPDATE prueba
    SET nombre='Rodriguez Guillen, Pablo'
    WHERE nombre='Perez Perez, Jose';
    
    
  