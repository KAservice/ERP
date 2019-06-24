#ifndef UREM_DMSprProducerModelGrpCFH                  
#define UREM_DMSprProducerModelGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprProducerModelGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprProducerModelGrpCF();                                                           
   ~TREM_DMSprProducerModelGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
