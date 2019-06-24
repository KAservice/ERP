#ifndef UREM_DMSprTypDefectCFH                  
#define UREM_DMSprTypDefectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprTypDefectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprTypDefectCF();                                                           
   ~TREM_DMSprTypDefectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
