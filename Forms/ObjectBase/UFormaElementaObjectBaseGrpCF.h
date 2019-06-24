#ifndef UFormaElementaObjectBaseGrpCFH                  
#define UFormaElementaObjectBaseGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaObjectBaseGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaObjectBaseGrpCF();                                                           
   ~TFormaElementaObjectBaseGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
