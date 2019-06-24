#ifndef UREM_FormaSpiskaSprTrebUslovCFH                  
#define UREM_FormaSpiskaSprTrebUslovCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaSpiskaSprTrebUslovCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaSpiskaSprTrebUslovCF();                                                           
   ~TREM_FormaSpiskaSprTrebUslovCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
