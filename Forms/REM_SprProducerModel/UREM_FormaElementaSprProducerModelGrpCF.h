#ifndef UREM_FormaElementaSprProducerModelGrpCFH                  
#define UREM_FormaElementaSprProducerModelGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprProducerModelGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprProducerModelGrpCF();                                                           
   ~TREM_FormaElementaSprProducerModelGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
