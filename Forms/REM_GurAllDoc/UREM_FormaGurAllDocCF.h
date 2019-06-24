#ifndef UREM_FormaGurAllDocCFH                  
#define UREM_FormaGurAllDocCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaGurAllDocCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaGurAllDocCF();                                                           
   ~TREM_FormaGurAllDocCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
