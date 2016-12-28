Pod::Spec.new do |s|
  s.name          = "HJMacros"
  s.version       = "0.1.0"
  s.summary       = "HJMacros: Macros used in Objective-C development"

  s.description   = <<-DESC
                   HJMacros: Macros used in Objective-C development.
                   DESC

  s.homepage      = "https://github.com/amisare/HJMacros"
  s.license       = { :type => "MIT", :file => "LICENSE" }
  s.author        = { "HaijunGu" => "243297288@qq.com" }
  s.social_media_url        = "http://www.jianshu.com/users/9df9f28ff266/latest_articles"

  s.source        = { :git => "https://github.com/amisare/HJMacros.git", :tag => s.version }
  s.requires_arc  = true
  s.ios.deployment_target   = '6.0'
  s.osx.deployment_target   = '10.8'

  s.default_subspec         = 'Core'

  s.subspec 'Core' do |ss|
    ss.source_files         = 'HJMacros/*.{h,m}'
  end

end
