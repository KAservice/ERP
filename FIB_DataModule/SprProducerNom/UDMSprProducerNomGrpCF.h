#ifndef UDMSprProducerNomGrpCFH                  
#define UDMSprProducerNomGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprProducerNomGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprProducerNomGrpCF();                                                           
   ~TDMSprProducerNomGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
