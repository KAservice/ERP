#ifndef UREM_DMSprTrebUslovCFH                  
#define UREM_DMSprTrebUslovCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprTrebUslovCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprTrebUslovCF();                                                           
   ~TREM_DMSprTrebUslovCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
