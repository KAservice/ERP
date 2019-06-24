#ifndef UREM_DMSprProducerSectionGrpCFH                  
#define UREM_DMSprProducerSectionGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprProducerSectionGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprProducerSectionGrpCF();                                                           
   ~TREM_DMSprProducerSectionGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
