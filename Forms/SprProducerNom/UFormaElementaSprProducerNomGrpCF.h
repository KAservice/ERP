#ifndef UFormaElementaSprProducerNomGrpCFH                  
#define UFormaElementaSprProducerNomGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprProducerNomGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprProducerNomGrpCF();                                                           
   ~TFormaElementaSprProducerNomGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
