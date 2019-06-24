#ifndef UREM_DMSprGrpModelCFH                  
#define UREM_DMSprGrpModelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprGrpModelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprGrpModelCF();                                                           
   ~TREM_DMSprGrpModelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
