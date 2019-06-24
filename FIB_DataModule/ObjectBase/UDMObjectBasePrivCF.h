#ifndef UDMObjectBasePrivCFH                  
#define UDMObjectBasePrivCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMObjectBasePrivCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMObjectBasePrivCF();                                                           
   ~TDMObjectBasePrivCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
