#ifndef UREM_FormaElementaSprProducerNeisprGrpCFH                  
#define UREM_FormaElementaSprProducerNeisprGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprProducerNeisprGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprProducerNeisprGrpCF();                                                           
   ~TREM_FormaElementaSprProducerNeisprGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
