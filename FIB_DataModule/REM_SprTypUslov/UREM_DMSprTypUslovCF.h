#ifndef UREM_DMSprTypUslovCFH                  
#define UREM_DMSprTypUslovCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprTypUslovCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprTypUslovCF();                                                           
   ~TREM_DMSprTypUslovCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
